# Created by: jon@netcraft.com
# $FreeBSD$

PORTNAME=	nrpep
PORTVERSION=	0.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netsaint.org/download/contrib/addons/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A netsaint addon for running plugins on remote hosts

DEPRECATED=	No more upstream, no more public distfiles
EXPIRATION_DATE=	2013-02-27

# Note that this port depends on neither netsaint-plugins OR netsaint, because it
# installs both a client and a server, and so could need EITHER. Bummer.
RUN_DEPENDS=  	p5-Crypt-TripleDES>=0:${PORTSDIR}/security/p5-Crypt-TripleDES

USE_PERL5_RUN=	yes

post-install:
	${CAT} pkg-message

.include <bsd.port.mk>
