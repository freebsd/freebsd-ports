# ex:ts=8
# New ports collection Makefile for: nmzmail
# Date created:		7 January 2005
# Whom:			fernan@iib.unsam.edu.ar
#
# $FreeBSD$
#

PORTNAME=	nmzmail
PORTVERSION=	0.1.3
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/ CENKES

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Fast mail searching for mutt

RUN_DEPENDS=	namazu:${PORTSDIR}/databases/namazu2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/nmzmail
PORTDOCS=	README	NEWS

pre-extract:
.if !defined(MAX_MAIL_DIRS)
	@ ${ECHO_MSG} "You can define MAX_MAIL_DIRS=n."
	@ ${ECHO_MSG} "nmzmail will only process this many mailboxes, the default is 32."
.endif

post-extract:
.if defined(MAX_MAIL_DIRS)
	@ ${SED} -i.bak -e 's/MAX_MAIL_DIRS 32/MAX_MAIL_DIRS ${MAX_MAIL_DIRS}/' \
	${WRKSRC}/src/nmzmail.c
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
