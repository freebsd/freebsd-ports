# Created by: amistry@am-productions.biz
# $FreeBSD$

PORTNAME=	hplip-plugin
PORTVERSION=	3.16.2
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://hplipopensource.com/hplip-web/plugin/
DISTNAME=	hplip-${DISTVERSION}-plugin
EXTRACT_SUFX=	.run

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Binary plugin for some HP Printers and All-in-One devices

LICENSE=	HPLIP_PLUGIN
LICENSE_NAME=	HPLIP Driver Plug-in License
LICENSE_PERMS=	none
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	hp-plugin:print/hplip

RESTRICTED=	License agreement is required

ONLY_FOR_ARCHS=	amd64 i386 # arm

PLUGINS=	fax/plugins/fax_marvell \
		prnt/plugins/hbpl1 \
		prnt/plugins/lj \
		scan/plugins/bb_escl \
		scan/plugins/bb_marvell \
		scan/plugins/bb_soap \
		scan/plugins/bb_soapht

PLIST_SUB+=	LINARCH="${LINARCH}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
LINARCH=	x86_32
.elif ${ARCH} == "amd64"
LINARCH=	x86_64
.endif

do-extract:
	@${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		--keep --noexec --nox11 --target ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -Wall -fPIC -c ${FILESDIR}/wrap.c -o ${WRKSRC}/wrap.o
.for p in ${PLUGINS}
	(cd ${WRKSRC} && ${BRANDELF} -t FreeBSD ${p:T}-${LINARCH}.so && \
		${CC} ${CFLAGS} ${LDFLAGS} -shared -fPIC -o ${p:T}.so wrap.o \
		${p:T}-${LINARCH}.so -Wl,-rpath,${PREFIX}/share/hplip/${p:H})
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/hplip/data/firmware
	${INSTALL_DATA} ${WRKSRC}/*.fw.gz \
		${STAGEDIR}${PREFIX}/share/hplip/data/firmware
	${MKDIR} ${PLUGINS:H:S,^,${STAGEDIR}${PREFIX}/share/hplip/,}
.for p in ${PLUGINS}
	${INSTALL_LIB} ${WRKSRC}/${p:T}-${LINARCH}.so \
		${STAGEDIR}${PREFIX}/share/hplip/${p}-${LINARCH}.so
	${INSTALL_LIB} ${WRKSRC}/${p:T}.so \
		${STAGEDIR}${PREFIX}/share/hplip/${p}.so
.endfor
	${INSTALL_DATA} ${WRKSRC}/plugin.spec ${STAGEDIR}${PREFIX}/share/hplip
	${MKDIR} ${STAGEDIR}/var/lib/hp
	${ECHO_CMD} '[plugin]' > ${STAGEDIR}/var/lib/hp/hplip.state
	${ECHO_CMD} 'installed = 1' >> ${STAGEDIR}/var/lib/hp/hplip.state
	${ECHO_CMD} 'eula = 1' >> ${STAGEDIR}/var/lib/hp/hplip.state
	${ECHO_CMD} 'version = ${PORTVERSION}' >> ${STAGEDIR}/var/lib/hp/hplip.state

.include <bsd.port.post.mk>
