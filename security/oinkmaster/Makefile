# ex:ts=8
# Ports collection makefile for:	oinkmaster
# Date created:			Jan 28, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	oinkmaster
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Help you update your snort rules after each update

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_REINPLACE=	yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		needs at least perl 5.6.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},g' \
		-e 's,"tPf","tf",' \
		${WRKSRC}/oinkmaster.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oinkmaster.pl ${PREFIX}/bin/oinkmaster
	${INSTALL_DATA} ${WRKSRC}/oinkmaster.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
