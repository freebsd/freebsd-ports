# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	archiveopteryx
PORTVERSION=	3.2.0
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	http://archiveopteryx.org/download/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Advanced PostgreSQL-based IMAP/POP server

LICENSE=	MIT

BROKEN_armv6=		fails to build: core/md5.cpp:55:5: 'register' storage class specifier is deprecated and incompatible with C++17
BROKEN_armv7=		fails to build: core/md5.cpp:55:5: 'register' storage class specifier is deprecated and incompatible with C++17
BROKEN_powerpc64=	fails to build: /bin/sh: clang: not found

BUILD_DEPENDS=	jam:devel/jam

USES=		perl5 ssl tar:bzip2
USE_PERL5=	build
WITH_PGSQL=	client

PORTDOCS=	COPYING README bsd.txt

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

USERS=		aox
GROUPS=		aox
PLIST_SUB+=	USERS="${USERS}"
PLIST_SUB+=	GROUPS="${GROUPS}"

JAM?=		${LOCALBASE}/bin/jam
JAMARG+=	-dx

.include <bsd.port.pre.mk>

# force Clang when on FreeBSD
.if ${OPSYS} == FreeBSD
JAMARG+=	"-sCLANG=1"
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
