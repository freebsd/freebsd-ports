# Created by: Tomasz Walaszek <tmwalaszek@gmail.com>
# $FreeBSD$

PORTNAME=	ptools
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://shewolf.com.pl/ptools/
PKGNAMESUFFIX=	2

MAINTAINER=	tmwalaszek@gmail.com
COMMENT=	Toolset based on Solaris ptools functionality

LICENSE=	BSD4CLAUSE

PLIST_FILES=	bin/pargs \
		bin/pwdx \
		bin/pldd \
		bin/ptree

NEED_ROOT=	yes

post-patch-script:
	@${REINPLACE_CMD} -e 's|/usr/local/bin|${STAGEDIR}${PREFIX}/bin|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|gcc|$${CC}|g' \
		${WRKSRC}/Makefile

post-install:
.for file in pargs pwdx pldd ptree
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
