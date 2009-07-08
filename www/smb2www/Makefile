# Ports collection makefile for:  smb2www
# Date created:			  Mar 25 2001
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	smb2www
PORTVERSION=	0.0.980804
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	smb2www
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.0.//g}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Windows Network client that is accessible through a web browser

RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba3 \
				${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
USE_PERL5=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/www/smb2www,${WWWDIR},g' -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/Install.pl

do-install:
	@cd ${WRKSRC}; ${PERL} ${WRKSRC}/Install.pl

.include <bsd.port.mk>
