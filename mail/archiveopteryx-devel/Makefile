# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	archiveopteryx
PORTVERSION=	3.2.99.20180207
PORTREVISION=	0
CATEGORIES=	mail
PKGNAMESUFFIX=	-devel

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Advanced PostgreSQL-based IMAP/POP server

LICENSE=	MIT

BROKEN_mips=		fails to build: /bin/sh: clang: not found
BROKEN_mips64=		fails to build: /bin/sh: clang: not found
BROKEN_powerpc64=	Does not build: /bin/sh: clang: not found

BUILD_DEPENDS=	jam:devel/jam

USE_GITHUB=	yes
GH_ACCOUNT=	aox
GH_PROJECT=	aox
GH_TAGNAME=	8a59400

USES=		perl5 ssl
USE_PERL5=	build
WITH_PGSQL=	client

PORTDOCS=	COPYING README license.txt

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

CONFLICTS=	archiveopteryx-[0-9]*

USERS=		aox
GROUPS=		aox
PLIST_SUB+=	USERS="${USERS}"
PLIST_SUB+=	GROUPS="${GROUPS}"

JAM?=		${LOCALBASE}/bin/jam

.include <bsd.port.pre.mk>

# force Clang when on FreeBSD
.if ${OPSYS} == FreeBSD
JAMARG=	"-sCLANG=1"
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
