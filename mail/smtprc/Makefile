# ex:ts=8
# Ports collection makefile for:  smtprc
# Date created:                Mon Mar 3, 2003
# Whom:                        Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	smtprc
PORTVERSION=	0.9.7
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A scanner for open SMTP relays

.if defined(WITH_GUI)
RUN_DEPENDS=	${SITE_PERL}/mach/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
PLIST_SUB+=	WITHGUI=""
.else
PLIST_SUB+=	WITHGUI="@comment "
.endif

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

pre-fetch:
.if defined(WITH_GUI)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Installed with GUI"
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press ctrl-c now, and define WITH_GUI for GUI"
	@${ECHO_MSG} ""
.endif

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
.if defined(WITH_GUI)
	${INSTALL_SCRIPT} ${WRKSRC}/gsmtprc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gsmtprc.1 ${PREFIX}/man/man1
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.if defined(WITH_GUI)
MAN1=		smtprc.1 gsmtprc.1
.else
MAN1=		smtprc.1
.endif

.include <bsd.port.mk>
