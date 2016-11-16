# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	pkg_tree
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Get a 'graphical' tree-overview of installed packages

USES=		perl5 shebangfix
SHEBANG_FILES=	pkg_tree

NO_ARCH=	yes

PLIST_FILES=	bin/pkg_tree man/man7/pkg_tree.7.gz

post-patch:
	@${REINPLACE_CMD} -e 's|__PREFIX__|${STAGEDIR}${PREFIX}|g ; \
		s|__INSTALL_MAN__|${INSTALL_MAN}|g ; \
		s|__INSTALL_SCRIPT__|${INSTALL_SCRIPT}|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
