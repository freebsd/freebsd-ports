# Ports collection makefile for:  smb2www
# Date created:			  Mar 25 2001
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	smb2www
PORTVERSION=	0.0.980804
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	smb2www
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.0.//g}

MAINTAINER=	ports@oven.org
COMMENT=	Windows Network client that is accessible through a web browser

RUN_DEPENDS=	httpd:${PORTSDIR}/${APACHE_PORT} \
		smbclient:${PORTSDIR}/net/samba \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

IS_INTERACTIVE=	yes
NO_BUILD=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}

do-install:
	@cd ${WRKSRC}; ${PERL} ${WRKSRC}/Install.pl

.include <bsd.port.mk>
