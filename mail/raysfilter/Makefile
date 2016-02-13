# $FreeBSD$

PORTNAME=	raysfilter
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	LOCAL/dinoex
DISTNAME=	rays-filter-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Configurable filter for Sendmail Milter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GNU-public-licence.txt

USES=		shebangfix
CTARGETS+=	rays-filter
CFLAGS+=	-Wall
LIBS+=		-lpthread -lmilter
SHEBANG_FILES=	mf-analyze
ETCFILES=	header-list.conf mail-filter.conf string-list.conf
BINFILES=	mf-reset mf-start mf-stop mf-archive mf-analyze mf-memory
DOCSFILES=	rays-filter.html install.html configure.html operate.html \
		utilities.html GNU-public-licence.txt copyright.txt README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.for i in ${CTARGETS}
${i}:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} -o ${i} ${i}.c ${LIBS} ${FLAGS}

.endfor

do-build:	${CTARGETS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rays-filter \
		${STAGEDIR}${PREFIX}/libexec/rays-filter
	${INSTALL_SCRIPT} ${WRKSRC}/mail-filter \
		${STAGEDIR}${PREFIX}/etc/rc.d/raysfilter.sh.sample
.for i in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail-filter
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/etc/mail-filter/${i}-dist
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.post.mk>
