# New ports collection makefile for:		jarl
# Date created:					10 November 2002
# Whom:						dd
#
# $FreeBSD$
#

PORTNAME=	jarl
PORTVERSION=	0.5001
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF
DISTNAME=	Jarl-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A Perl/Tk Jabber client

RUN_DEPENDS=	ptksh:${PORTSDIR}/x11-toolkits/p5-Tk \
		${SITE_PERL}/Net/Jabber/IQ.pm:${PORTSDIR}/net-im/p5-Net-Jabber

NO_BUILD=	yes

USE_PERL5=	yes

makeplist:
	${ECHO_CMD} bin/jarl > ${PLIST}
	${FIND} ${PREFIX}/share/jarl ! -name "*.orig" -type f -print | ${CUT} -d/ -f4- >> \
		${PLIST}
	${FIND} ${PREFIX}/share/jarl -type d -print | ${CUT} -d/ -f4- | \
		${SORT} -r | ${SED} 's/^/@dirrm /' >> ${PLIST}

post-patch:
	${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/jarl

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/lib
	${MKDIR} ${DATADIR}/bitmaps
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${DATADIR}/lib)
	(cd ${WRKSRC}/bitmaps && ${COPYTREE_SHARE} \* ${DATADIR}/bitmaps)
	${INSTALL_SCRIPT} ${WRKSRC}/jarl ${PREFIX}/bin

.include <bsd.port.mk>
