# New ports collection makefile for:	qmail-notify
# Date created:		24 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	qmail-notify
PORTVERSION=	0.93
PORTCOMMENT=	Delayed delivery notification for qmail
CATEGORIES=	mail
MASTER_SITES=	http://untroubled.org/qmail-notify/

MAINTAINER=	sergei@kolobov.com

EXAMPLES=	cron.hourly message.txt
DOCS=		ANNOUNCEMENT NEWS README TODO

pre-build:
	${ECHO_CMD} ${PREFIX}/bin   > ${WRKSRC}/conf-bin
	${ECHO_CMD} ${CC} ${CFLAGS} -DHAVE_SRANDOM > ${WRKSRC}/conf-cc

do-install:
	cd ${WRKSRC} && ./installer
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
