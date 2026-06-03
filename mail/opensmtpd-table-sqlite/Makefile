PORTNAME=	opensmtpd-table-sqlite
DISTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	mail

PATCH_SITES=	https://github.com/OpenSMTPD/table-sqlite/commit/
PATCHFILES=	f3c46da1cbbb2a9d32cd9b4cf31e9fdb5b941a16.patch:-p1

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	SQLite table for OpenSMTPD
WWW=		https://github.com/opensmtpd/table-sqlite

LICENSE=	ISCL

USES=		autoreconf localbase sqlite
GNU_CONFIGURE=	yes

PATCH_ARGS=	-p1

USE_GITHUB=	yes
GH_ACCOUNT=	opensmtpd
GH_PROJECT=	table-sqlite

PLIST_FILES=	libexec/opensmtpd/table-sqlite \
		share/man/man5/table-sqlite.5.gz

post-patch:
	${REINPLACE_CMD} '/^smtpdir/s|smtpd$$|opensmtpd|' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
