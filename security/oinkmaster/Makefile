# ex:ts=8
# Ports collection makefile for:	oinkmaster
# Date created:			Jan 28, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	oinkmaster
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.it.su.se/pub/users/andreas/oinkmaster/

MAINTAINER=	jim@corebsd.or.id
COMMENT=	Help you update your snort rules after each update

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_REINPLACE=	yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},g;\
		s,\./oinkmaster.conf,${PREFIX}/etc/oinkmaster.conf,g' \
		${WRKSRC}/oinkmaster.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oinkmaster.pl ${PREFIX}/bin/oinkmaster
	${INSTALL_DATA} ${WRKSRC}/oinkmaster.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
