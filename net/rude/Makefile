# New ports collection makefile for:	rude
# Date created:		rude
# Whom:			Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	rude
PORTVERSION=	0.70
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	Rude is a Real-time UDP Data Emitter and Collector (crude)

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	--with-debug-lvl=3
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN8=		rude.8 crude.8

DOC_FILES=	README README.rude README.crude TODO example.cfg
EXAMPLE_FILES=	crude_jitter.pl crude_parse.pl dump2trace.pl

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/grude/grude ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/DOC/${FILE} ${DOCSDIR}
.endfor
.for FILE in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/scripts/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>
