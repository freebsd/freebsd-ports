# ex:ts=8
# Ports collection makefile for:  smtprc
# Date created:                Mon Mar 3, 2003
# Whom:                        Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	smtprc
PORTVERSION=	0.9.5b
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mich@freebsdcluster.org
COMMENT=	A scanner for open SMTP relays

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s,-Wall -g,${CFLAGS},g ; \
	    s,gcc,${CC},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/auto.conf ${PREFIX}/etc/${PORTNAME}/auto.conf.sample
	${INSTALL_DATA} ${WRKSRC}/email.tmpl ${PREFIX}/etc/${PORTNAME}/email.tmpl.sample
	${INSTALL_DATA} ${WRKSRC}/rcheck.conf ${PREFIX}/etc/${PORTNAME}/rcheck.conf.sample
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

MAN1=		smtprc.1
.include <bsd.port.mk>
