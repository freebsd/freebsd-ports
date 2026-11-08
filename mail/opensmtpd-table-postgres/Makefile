PORTNAME=	opensmtpd-table-postgres
DISTVERSION=	1.1.1
CATEGORIES=	mail

MAINTAINER=	eric901@pouik.org
COMMENT=	PostgreSQL table for OpenSMTPD
WWW=		https://github.com/opensmtpd/table-postgres

LICENSE=	ISCL

USES=		autoreconf localbase pgsql
USE_GITHUB=	yes
GH_ACCOUNT=	opensmtpd
GH_PROJECT=	table-postgres
GNU_CONFIGURE=	yes

PLIST_FILES=	libexec/opensmtpd/table-postgres \
		share/man/man5/table-postgres.5.gz

.include <bsd.port.mk>
