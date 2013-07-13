# Created by: amistry@am-productions.biz
# $FreeBSD$

PORTNAME=	hplip-plugin
PORTVERSION=	3.13.6
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/printdriver/auxfiles/HP/plugins/
DISTNAME=	hplip-${DISTVERSION}-plugin
EXTRACT_SUFX=	.run

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Binary plugin for some HP Printers and All-in-One devices

RUN_DEPENDS=	hp-plugin:${PORTSDIR}/print/hplip

USE_PYTHON=	yes
NO_BUILD=	yes
RESTRICTED=	User must accept the license terms
NO_PACKAGE=	${RESTRICTED}
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/plugin_tmp

ONLY_FOR_ARCHS=	amd64 i386

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	LINARCH="x86_32"
.elif ${ARCH} == "amd64"
PLIST_SUB+=	LINARCH="x86_64"
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${SH} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} --keep --noexec

post-patch:
#	${REINPLACE_CMD} -e 's|ok, ans = tui.enter_yes_no.*|ok, ans = 1, 1|' \
#		${WRKSRC}/plugin_install.py
	${REINPLACE_CMD} -e 's|rules,||;s|rules_alt,||' ${WRKSRC}/plugin.spec
	${REINPLACE_CMD} -e 's|/etc/hp|${PREFIX}&|g' \
		${WRKSRC}/plugin_install.py

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} -B plugin_install.py

.include <bsd.port.post.mk>
