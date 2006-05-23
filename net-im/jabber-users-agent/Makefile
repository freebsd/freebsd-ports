# New ports collection makefile for:	jabber-users-agent
# Date created:		2005-06-07
# Whom:			Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	users-agent
PORTVERSION=	1.2
CATEGORIES=	net-im
MASTER_SITES=	http://jabberstudio.rediris.es/users-agent/ \
		http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	jabber-
DISTNAME=	Users-Agent-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A Perl based Jabber User Directory

NO_BUILD=	yes
STRIP=
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INST_DIR=	${PREFIX}/lib/jabber/${PORTNAME}
PORTDOCS=	README INSTALL
USE_PERL5=	yes
USE_RC_SUBR=	jabber-users-agent.sh
SUB_LIST+=	PERL=${PERL}

BUILD_DEPENDS+=	${SITE_PERL}/Net/Jabber.pm:${PORTSDIR}/net-im/p5-Net-Jabber \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e 's|config.xml|${PREFIX}/etc/jabber-users-agent.xml|g' \
		${WRKSRC}/users-agent
	@${PERL} -pi -e 's|%%PERL%%|${PERL}|g' ${WRKSRC}/users-agent

do-install:
	${MKDIR} ${INST_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${WRKSRC}/createDB ${INST_DIR}

.if !exists(${PREFIX}/etc/jabber-users-agent.xml)
	${INSTALL_DATA} ${WRKSRC}/config.xml ${PREFIX}/etc/jabber-users-agent.xml
.endif
	${INSTALL_DATA} ${WRKSRC}/config.xml ${PREFIX}/etc/jabber-users-agent.xml.sample

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S!^!${WRKSRC}/!} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
