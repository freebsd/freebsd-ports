# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cups
# Date created:		2003-01-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cups-base
PORTVERSION=	${CUPS_PORTVER}
PORTREVISION=	${CUPS_PORTREV}
PORTEPOCH=	${CUPS_PORTEPOCH}
CATEGORIES=	print
MASTER_SITES=	${CUPS_MASTER_SITES}

MAINTAINER=	asa@gascom.ru
COMMENT=	The Common UNIX Printing System: headers, libs, & daemons

USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

MANLANG=	"" fr

post-patch:
	@${REINPLACE_CMD} -e '/SILENT/d' \
		${WRKSRC}/Makedefs.in
	@${REINPLACE_CMD} -e '/LN/d' -e '/cat/d' \
		${WRKSRC}/man/Makefile ${WRKSRC}/man/fr/Makefile

pre-install:
	@${ECHO_MSG} "===>" Stopping cupsd ...
	-killall cupsd || ${TRUE}
	${RM} -fr ${PREFIX}/etc/cups/certs/* || ${TRUE}

post-install:
	${MKDIR} ${CUPS_ETCDIR}
.for f in classes.conf client.conf cupsd.conf printers.conf
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${CUPS_ETCDIR}/${f}.N
	cd ${CUPS_ETCDIR}; if test ! -f ${f}; then ${CP} -p ${f}.N ${f}; fi
.endfor # classes.conf client.conf cupsd.conf printers.conf
.for f in mime.convs mime.types
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${CUPS_ETCDIR}/${f}
.endfor # mime.convs mime.types
	cd ${CUPS_RCDIR}; ${MV} cups cups.sh.sample
	${FIND} ${PREFIX}/man/cat* -type l -name '*.0' -delete
	${MKDIR} ${CUPS_SPOOLDIR} ${CUPS_SPOOLDIR}/tmp
	${CHOWN} -R ${CUPSOWN}:${CUPSGRP} ${CUPS_SPOOLDIR}
	${CHMOD} -R g+w ${CUPS_SPOOLDIR}
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/../../print/cups/Makefile.common"
.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>
