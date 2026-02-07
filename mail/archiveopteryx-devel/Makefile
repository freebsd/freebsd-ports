PORTNAME=	archiveopteryx
PORTVERSION=	3.2.99.20181030
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-devel

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Advanced PostgreSQL-based IMAP/POP server
WWW=		https://www.archiveopteryx.org/

LICENSE=	MIT

BUILD_DEPENDS=	jam:devel/jam

USE_GITHUB=	yes
GH_ACCOUNT=	aox
GH_PROJECT=	aox
GH_TAGNAME=	96ab17e

USES=		compiler perl5 ssl
USE_PERL5=	build

CONFLICTS_INSTALL=	archiveopteryx # bin/aox bin/aoxdeliver bin/aoxexport bin/aoximport

PORTDOCS=	COPYING README license.txt

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

CONFLICTS=	archiveopteryx

USERS=		aox
GROUPS=		aox
PLIST_SUB+=	USERS="${USERS}"
PLIST_SUB+=	GROUPS="${GROUPS}"

JAM?=		${LOCALBASE}/bin/jam

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

# force Clang when on FreeBSD with clang in base
.if ${OPSYS} == FreeBSD
.if ${CHOSEN_COMPILER_TYPE} == clang
JAMARG+=	"-sCLANG=1"
.endif
.endif

post-patch:
	@${EGREP} -Rl '%%[[:alpha:]]+%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,%%PREFIX%%,${PREFIX},g'
	${REINPLACE_CMD} -e "s|\(C++FLAGS =\)|\1 -I${OPENSSLINC}|g" \
		-e"s|INSTALLROOT ?= \"\" ;|INSTALLROOT = \"${STAGEDIR}\" ;|" \
		${WRKSRC}/Jamsettings
	${REINPLACE_CMD} -e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" \
		${WRKSRC}/server/Jamfile

do-build:
	@cd ${WRKSRC} && ${JAM} ${JAMARG}

do-install:
	@cd ${WRKSRC} && ${JAM} ${JAMARG} install

.include <bsd.port.post.mk>
