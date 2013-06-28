# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	opendmarc
PORTVERSION=	1.1.3
CATEGORIES=	mail security
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME} \
			${PORTNAME}/Previous%20Releases

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	DMARC library an milter implementation

LICENSE=		BSD SENDMAIL
LICENSE_COMB=		multi

LICENSE_FILE_SENDMAIL=	${WRKSRC}/LICENSE.Sendmail
LICENSE_GROUPS_SENDMAIL=	FSF OSI
LICENSE_NAME_SENDMAIL=	Sendmail Open Source License
LICENSE_PERMS_SENDMAIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_RC_SUBR=	opendmarc
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes

PORTDOCS=	*
MAN5=		opendmarc.conf.5
MAN8=		opendmarc-check.8 opendmarc-expire.8 opendmarc-import.8 \
		opendmarc-params.8 opendmarc-reports.8 opendmarc.8

post-install:
	@${MKDIR} ${PREFIX}/etc/mail
	${INSTALL_DATA} \
		${WRKSRC}/opendmarc/opendmarc.conf.sample ${PREFIX}/etc/mail

.include <bsd.port.mk>
