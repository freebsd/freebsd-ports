# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=		vimpager
PORTVERSION=	1.8.9
CATEGORIES=		sysutils
MASTER_SITES=	http://github.com/rkitover/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Use ViM as a pager

LICENSE=		BSD2CLAUSE

RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

OPTIONS_DEFINE=		VIMCAT TACOS BOB BOB2 BOB3
OPTIONS_DEFAULT=	VIMCAT
VIMCAT_DESC=		Install vimcat(1) (requires shells/bash)
VIMCAT_RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
VIMCAT_PLIST_FILES=	bin/vimcat man/man1/vimcat.1.gz

VIMCAT_IMPLIES=		TACOS
TACOS_IMPLIES=		BOB
BOB_IMPLIES=		BOB2
BOB2_IMPLIES=		BOB3
TACOS_RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl

PLIST_FILES=		bin/${PORTNAME} etc/${PORTNAME}rc man/man1/${PORTNAME}.1.gz

.include <bsd.port.options.mk>
bob:
	@echo ${PORT_OPTIONS:M}
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vimcat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/vimcat.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
