# New ports collection makefile for:	sipcalc
# Date created:				24.03.2002
# Whom:					Janos.Mohacsi@dante.org.uk
#
# $FreeBSD$
#

PORTNAME=	sipcalc
PORTVERSION=	1.1.0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.routemeister.net/projects/sipcalc/files/

MAINTAINER=	Janos.Mohacsi@dante.org.uk

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
MAN1=		sipcalc.1

post-install:
	@${ECHO} '======================================================='
	@${ECHO} 'If you want CGI support copy sipcalc-www to your CGI '
	@${ECHO} 'directory. Copy also the docs/web.html into the appropriate '
	@${ECHO} 'web directory. This is not done, since CGI and web setup'
	@${ECHO} 'has to be done according to your local policy.'
	@${ECHO} '======================================================='

.include <bsd.port.mk>
