# Created by: Kay Lehmann

PORTNAME=	lgrind
PORTVERSION=	3.67
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	http://mirrors.ctan.org/support/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce beautiful listings of source code with LaTeX

# Converted from RESTRICTED
LICENSE=	lgrind-license
LICENSE_NAME=	lgrind
LICENSE_TEXT=	According to the README-file there is a license issue \
		because of non-free code. Check the README file within \
		the source tarball. No response from author of some code \
		this port is based on.
LICENSE_PERMS=	auto-accept

USE_TEX=	latex texhash

USES=		zip

post-patch:
# PREFIX safeness
	@${REINPLACE_CMD} -E \
		-e s'|^(BASEDIR).*$$|\1=${STAGEDIR}${PREFIX}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E \
		-e s'|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/Makefile
# C{C,FLAGS} safeness
	@${REINPLACE_CMD} -E \
		-e s'|^(CC).*$$|\1=${CC}|' \
		-e s'|^(CFLAGS).*$$|\1=${CFLAGS}|' \
		${WRKSRC}/source/Makefile

.include <bsd.port.mk>
