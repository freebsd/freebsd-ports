# New ports collection makefile for:	mod_backhand
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_backhand
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://mirrors.omniti.com/mod_backhand/ \
		http://people.FreeBSD.org/~seanc/ports/mod_backhand/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that allows seamless redirection and load balancing of HTTP requests

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apxs="${APXS}"

# mod_backhand's install target is buggered.
do-install:
	${APXS} -i -A -n ${PORTNAME:S/mod_//g} ${WRKSRC}/${PORTNAME}.so

.include <bsd.port.mk>
