# Created by: amistry@am-productions.biz
# $FreeBSD$

PORTNAME=	hplip-plugin
PORTVERSION=	3.14.4
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://hplipopensource.com/hplip-web/plugin/
DISTNAME=	hplip-${DISTVERSION}-plugin
EXTRACT_SUFX=	.run

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Binary plugin for some HP Printers and All-in-One devices

RUN_DEPENDS=	hp-plugin:${PORTSDIR}/print/hplip

RESTRICTED=	License agreement is required

USES=		python
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/plugin_tmp
HPLIP_FAKEDIR=	${WRKDIR}/hplip_fakedir

ONLY_FOR_ARCHS=	amd64 i386

PLUGIN_LINKS=	fax/plugins/fax_marvell \
		prnt/plugins/hbpl1 \
		prnt/plugins/lj \
		scan/plugins/bb_marvell \
		scan/plugins/bb_soap \
		scan/plugins/bb_soapht

PLUGIN_DIRS=	data/firmware \
		data/plugins \
		fax/plugins \
		prnt/plugins \
		scan/plugins

PLIST_SUB+=	LINARCH="${LINARCH}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
LINARCH=	x86_32
.elif ${ARCH} == "amd64"
LINARCH=	x86_64
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} --keep --noexec

post-patch:
	${REINPLACE_CMD} -e 's|ok, ans = tui.enter_yes_no.*|ok, ans = 1, 1|' \
		${WRKSRC}/plugin_install.py
	${REINPLACE_CMD} -e 's|rules,||;s|rules_alt,||' ${WRKSRC}/plugin.spec
	${REINPLACE_CMD} -e 's|/etc/hp|${HPLIP_FAKEDIR}|g' \
		${WRKSRC}/plugin_install.py

do-install:
# fake hplip installation
	${MKDIR} ${HPLIP_FAKEDIR}
	${SED} -e 's,${LOCALBASE}/share/hplip,${HPLIP_FAKEDIR},' \
		${LOCALBASE}/etc/hp/hplip.conf > ${HPLIP_FAKEDIR}/hplip.conf
	${MKDIR} ${HPLIP_FAKEDIR}
	${LN} -sf ${LOCALBASE}/share/hplip/base ${HPLIP_FAKEDIR}
	${LN} -sf ${LOCALBASE}/share/hplip/prnt ${HPLIP_FAKEDIR}
	${CP} -R ${LOCALBASE}/share/hplip/installer ${HPLIP_FAKEDIR}
	${REINPLACE_CMD} -e 's,HOMEDIR = .*,HOMEDIR = "${STAGEDIR}${PREFIX}/share/hplip",' \
		${HPLIP_FAKEDIR}/installer/pluginhandler.py
# install hplip-plugin
	${MKDIR} ${PLUGIN_DIRS:S,^,${STAGEDIR}${PREFIX}/share/hplip/,}
	(cd ${WRKSRC} && ${PYTHON_CMD} -B plugin_install.py)
.for i in ${PLUGIN_LINKS}
	${LN} -sf ${i:T}-${LINARCH}.so ${STAGEDIR}${PREFIX}/share/hplip/${i}.so
.endfor

.include <bsd.port.post.mk>
