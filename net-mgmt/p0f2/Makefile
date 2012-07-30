# New ports collection makefile for:	p0f2
# Date created:				2012-07-30
# Whom:					Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	p0f2
PORTVERSION=	2.0.8
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://lcamtuf.coredump.cx/p0f/ \
		http://farrokhi.net/distfiles/
DISTNAME=	p0f-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	catone@cpan.org
COMMENT=	Passive OS fingerprinting tool

CONFLICTS=	p0f-3.*

USE_GMAKE=	yes
ALL_TARGET=	all p0fq tools
PORTDOCS=	COPYING CREDITS ChangeLog KNOWN_BUGS README TODO win-memleak.txt
MAN1=		p0f.1
WRKSRC=		${WRKDIR}/p0f

post-patch:
.for f in config.h doc/README
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/${f}
.endfor

do-install:
.for ii in p0f test/p0fq test/sendack test/sendack2 test/sendsyn
	${INSTALL_PROGRAM} ${WRKSRC}/${ii} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/p0frep ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/p0f
.for ii in . a. o. r.
	${INSTALL_DATA} ${WRKSRC}/p0f${ii}fp ${PREFIX}/etc/p0f
.endfor
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
