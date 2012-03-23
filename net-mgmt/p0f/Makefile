# New ports collection makefile for:	p0f
# Date created:				2000-06-12
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	p0f
PORTVERSION=	3.03b
PORTREVISION=	1
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://lcamtuf.coredump.cx/p0f3/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Passive OS fingerprinting tool

PLIST_FILES=	bin/p0f bin/p0f-client bin/p0f-sendsyn \
		bin/p0f-sendsyn6 etc/p0f.fp
PORTDOCS=	COPYING ChangeLog README TODO existential-notes.txt extra-sigs.txt

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/README
	@${REINPLACE_CMD} -e 's|p0f.fp|${PREFIX}/etc/p0f.fp|g' ${WRKSRC}/config.h

do-install:
.for ii in p0f tools/p0f-client tools/p0f-sendsyn tools/p0f-sendsyn6
	${INSTALL_PROGRAM} ${WRKSRC}/${ii} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/p0f.fp ${PREFIX}/etc/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
