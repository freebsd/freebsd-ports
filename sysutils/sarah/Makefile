# Created by: Matthew Pounsett <mattp@conundrum.com>
# $FreeBSD$

PORTNAME=	sarah
PORTVERSION=	0.9.1b
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.conundrum.com/pub/sarah/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Syslog automated Rotation and Archive Handler

DEPRECATED=	No more upstream, no more public distfiles
EXPIRATION_DATE=	2013-02-27

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		sarah.1
PLIST_FILES=	bin/sarah etc/sarah.conf.sample
PORTDOCS=	README CHANGES TODO

do-configure:
	@${PERL} -pi.orig -e "s|/usr/local|${PREFIX}|" ${WRKSRC}/sarah

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sarah ${PREFIX}/bin && \
	${INSTALL_DATA} ${WRKSRC}/sarah.conf.sample ${PREFIX}/etc && \
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
.endif

.include <bsd.port.mk>
