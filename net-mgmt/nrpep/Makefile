# New ports collection makefile for:	nrpep
# Date created: 10 April 2002
# Whom:		jon@netcraft.com
#
# $FreeBSD$

PORTNAME=	nrpep
PORTVERSION=	0.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netsaint.org/download/contrib/addons/

MAINTAINER=	jon@netcraft.com
COMMENT=	A netsaint addon for running plugins on remote hosts

# Note that this port depends on neither netsaint-plugins OR netsaint, because it
# installs both a client and a server, and so could need EITHER. Bummer.
RUN_DEPENDS=  	${SITE_PERL}/Crypt/TripleDES.pm:${PORTSDIR}/security/p5-Crypt-TripleDES

USE_PERL5_RUN=	yes

post-install:
	${CAT} pkg-message

.include <bsd.port.mk>
