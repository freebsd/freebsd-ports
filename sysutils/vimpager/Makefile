# Created by:					Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vimpager
PORTVERSION=	1.7.8
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/rkitover/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Use ViM as a pager

RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

FETCH_ARGS=	-prR

PLIST_FILES=	bin/${PORTNAME} bin/vimcat etc/${PORTNAME}rc
MAN1=		${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vimcat ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc ${PREFIX}/etc

.include <bsd.port.mk>
