# New ports collection makefile for:	log_analysis
# Date created:				5 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	log_analysis
PORTVERSION=	0.41
CATEGORIES=	sysutils
MASTER_SITES=	http://lug.umbc.edu/~mabzug1/

MAINTAINER=	petef@FreeBSD.org

USE_PERL5=	yes

GNU_CONFIGURE=	yes

MAN1=	log_analysis.1

post-patch:
	@${PERL} -pi -e 's!perldoc!pod2man!' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/share/examples/log_analysis
	${INSTALL_DATA} ${WRKSRC}/doc/sample-new.conf \
		${PREFIX}/share/examples/log_analysis
	${INSTALL_DATA} ${WRKSRC}/doc/sample-qpopper.conf \
		${PREFIX}/share/examples/log_analysis

.include <bsd.port.mk>
