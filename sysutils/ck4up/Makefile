# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ck4up
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://jue.li/crux/ck4up/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check HTTP and FTP sites for updates

RUN_DEPENDS=	rubygem-gdbm>=2.0.0,2:databases/rubygem-gdbm

NO_BUILD=	yes
NO_ARCH=	yes
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

PORTEXAMPLES=	ck4up.conf

PLIST_FILES=	bin/ck4up \
		man/man1/ck4up.1.gz

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ck4up.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
