# New ports collection makefile for:		jarl
# Date created:					10 November 2002
# Whom:						dd
#
# $FreeBSD$
#

PORTNAME=	jarl
PORTVERSION=	0.5001
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Jarl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Perl/Tk Jabber client

RUN_DEPENDS=	ptksh:${PORTSDIR}/x11-toolkits/p5-Tk \
		${SITE_PERL}/Net/Jabber/IQ.pm:${PORTSDIR}/net/p5-Net-Jabber

NO_BUILD=	yes

USE_REINPLACE=	yes
USE_PERL5=	yes

makeplist:
	${ECHO_CMD} bin/jarl > ${PLIST}
	${FIND} ${PREFIX}/share/jarl -type f -print | ${CUT} -d/ -f4- >> \
		${PLIST}
	${FIND} ${PREFIX}/share/jarl -type d -print | ${CUT} -d/ -f4- | \
		${SORT} -r | ${SED} 's/^/@dirrm /' >> ${PLIST}

post-patch:
	${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/jarl

do-install:
	${MKDIR} ${PREFIX}/share/jarl
	${INSTALL_SCRIPT} ${WRKSRC}/jarl ${PREFIX}/bin
	cd ${WRKSRC} && ${FIND} lib bitmaps -type d -print | while read d; do \
		${MKDIR} ${PREFIX}/share/jarl/$$d; \
		${FIND} $$d -maxdepth 1 -type f -print | \
			${XARGS} -t -J% ${INSTALL_DATA} % \
			${PREFIX}/share/jarl/$$d; \
	done;

.include <bsd.port.mk>
