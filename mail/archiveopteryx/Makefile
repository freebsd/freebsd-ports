PORTNAME=	archiveopteryx
PORTVERSION=	3.2.0.20260429
PORTREVISION=	0
CATEGORIES=	mail

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Advanced PostgreSQL-based IMAP/POP server
WWW=		https://www.archiveopteryx.org/

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/doc/readme/license.txt

BUILD_DEPENDS=	jam:devel/jam \
		idnkit2>0:dns/idnkit2

USE_GITHUB=	yes
GH_ACCOUNT=	aox
GH_PROJECT=	aox
GH_TAGNAME=	1f9a987

PORTDOCS=	COPYING README

USES=		compiler perl5 ssl
USE_PERL5=	build

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

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
	# copy some PORTDOCS to WRKSRC like in a normal release
	${CP} ${WRKSRC}/doc/readme/COPYING ${WRKSRC}/
	${CP} ${WRKSRC}/doc/readme/README ${WRKSRC}/

do-build:
	@cd ${WRKSRC} && ${JAM} ${JAMARG}

do-install:
	@cd ${WRKSRC} && ${JAM} ${JAMARG} install

.include <bsd.port.post.mk>
