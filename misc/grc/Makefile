# ex:ts=8
# New ports collection makefile for:	grc
# Date created:			Mar 25, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grc
PORTVERSION=	1.0.1
CATEGORIES=	misc
MASTER_SITES=	http://melkor.dnp.fmph.uniba.sk/~garabik/grc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org

USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

MAN1=	grc.1 grcat.1

post-patch:
.for file in grc grcat
	@${PERL} -pi -e "s|%%PYTHON_CMD%%|${PYTHON_CMD}|g ; \
		s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

do-install:
.for file in grc grcat ${MAN1}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${file} ${MAN1PREFIX}/man/man1
.endfor
	${MKDIR} ${PREFIX}/share/grc
	${CP} ${WRKSRC}/conf.* ${PREFIX}/share/grc
	${CP} ${WRKSRC}/grc.conf ${PREFIX}/etc/grc.conf

.include <bsd.port.mk>
