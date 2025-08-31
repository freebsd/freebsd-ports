PORTNAME=	hplip-plugin
PORTVERSION=	3.24.4
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://developers.hp.com/sites/default/files/ \
		https://www.openprinting.org/download/printdriver/auxfiles/HP/plugins/
DISTNAME=	hplip-${DISTVERSION}-plugin
EXTRACT_SUFX=	.run

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Binary plugin for some HP Printers and All-in-One devices
WWW=		https://developers.hp.com/hp-linux-imaging-and-printing/binary_plugin.html

# License agreement is required
LICENSE=	HPLIP_PLUGIN
LICENSE_NAME=	HPLIP Driver Plug-in License
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	none

ONLY_FOR_ARCHS=	aarch64 amd64 i386

RUN_DEPENDS=	hplip>=${PORTVERSION}<${PORTVERSION:R}.$$((${PORTVERSION:E}+1)):print/hplip

PORTSCOUT=	ignore:1

PLUGINS=	fax/plugins/fax_marvell \
		prnt/plugins/hbpl1 \
		prnt/plugins/lj \
		scan/plugins/bb_escl \
		scan/plugins/bb_marvell \
		scan/plugins/bb_soap \
		scan/plugins/bb_soapht

PLIST_SUB+=	LINARCH="${LINARCH}"

.include <bsd.port.options.mk>

.if ${ARCH} == "aarch64"
LINARCH=	arm64
.elif ${ARCH} == "amd64"
LINARCH=	x86_64
.elif ${ARCH} == "i386"
LINARCH=	x86_32
.endif

do-extract:
	@${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		--keep --noexec --nox11 --target ${WRKSRC}

do-build:
	${MKDIR} ${WRKSRC}/build
	${CC} ${CFLAGS} -Wall -fPIC -c ${FILESDIR}/wrap.c \
		-o ${WRKSRC}/build/wrap.o
.for p in ${PLUGINS}
	${BRANDELF} -t FreeBSD ${WRKSRC}/${p:T}-${LINARCH}.so
	(cd ${WRKSRC}/build \
	&& ${CC} -shared -fPIC -o ${p:T}-${LINARCH}.so wrap.o \
	&& ${CC} ${CFLAGS} ${LDFLAGS} -shared -fPIC -o ${p:T}.so wrap.o \
		${p:T}-${LINARCH}.so -Wl,-rpath,${PREFIX}/share/hplip/${p:H})
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/hplip/data/firmware
	${INSTALL_DATA} ${WRKSRC}/*.fw.gz \
		${STAGEDIR}${PREFIX}/share/hplip/data/firmware
	${MKDIR} ${PLUGINS:H:S,^,${STAGEDIR}${PREFIX}/share/hplip/,}
.for p in ${PLUGINS}
# -m 555 because HPLIP checks that the plugins are +x.
	${INSTALL_LIB} -m 555 ${WRKSRC}/${p:T}-${LINARCH}.so \
		${STAGEDIR}${PREFIX}/share/hplip/${p}-${LINARCH}.so
	${INSTALL_LIB} -m 555 ${WRKSRC}/build/${p:T}.so \
		${STAGEDIR}${PREFIX}/share/hplip/${p}.so
.endfor
	${INSTALL_DATA} ${WRKSRC}/plugin.spec ${STAGEDIR}${PREFIX}/share/hplip
	${MKDIR} ${STAGEDIR}/var/lib/hp
	${ECHO_CMD} '[plugin]' > ${STAGEDIR}/var/lib/hp/hplip.state
	${ECHO_CMD} 'installed = 1' >> ${STAGEDIR}/var/lib/hp/hplip.state
	${ECHO_CMD} 'eula = 1' >> ${STAGEDIR}/var/lib/hp/hplip.state
	${ECHO_CMD} 'version = ${PORTVERSION}' >> ${STAGEDIR}/var/lib/hp/hplip.state

.include <bsd.port.mk>
