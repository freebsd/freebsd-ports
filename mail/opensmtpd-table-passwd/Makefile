PORTNAME=	opensmtpd-table-passwd
DISTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	mail

MAINTAINER=	bsd@leonardtemplin.de
COMMENT=	OpenSMTPD passwd table support
WWW=		https://github.com/opensmtpd/table-passwd

LICENSE=	ISCL

USES=		autoreconf localbase
USE_GITHUB=	yes
GH_ACCOUNT=	opensmtpd
GH_PROJECT=	table-passwd
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	opensmtpd-extras-table-passwd-*

PATCH_ARGS=	-p1

PLIST_FILES=	libexec/opensmtpd/table-passwd \
		share/man/man5/table-passwd.5.gz

post-patch:
	${REINPLACE_CMD} '/^smtpdir/s|smtpd$$|opensmtpd|' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
