PORTNAME=	opensmtpd-table-socketmap
DISTVERSION=	1.1.1
CATEGORIES=	mail

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Socketmap table for OpenSMTPD
WWW=		https://github.com/opensmtpd/table-socketmap

LICENSE=	ISCL

USES=		autoreconf localbase
GNU_CONFIGURE=	yes

PATCH_ARGS=	-p1

USE_GITHUB=	yes
GH_ACCOUNT=	opensmtpd
GH_PROJECT=	table-socketmap

PLIST_FILES=	libexec/opensmtpd/table-socketmap \
		share/man/man5/table-socketmap.5.gz

post-patch:
	${REINPLACE_CMD} '/^smtpdir/s|smtpd$$|opensmtpd|' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
