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

MAINTAINER=	alane@FreeBSD.org

pre-install:
	-@${ECHO_CMD} "===>" Stopping cupsd ...
	-killall cupsd || true
	-rm -fr ${PREFIX}/etc/cups/certs/* || true

post-install:
	cd ${CUPS_RCDIR}; ${MV} cups cups.sh.sample
	${FIND} ${PREFIX}/man/cat* -type l -name '*.0' -delete
	${FIND} ${PREFIX}/man/fr/cat* -type l -name '*.0' -delete
	${MKDIR} ${CUPS_SPOOLDIR} ${CUPS_SPOOLDIR}/tmp
	${CHOWN} -R ${CUPSOWN}:${CUPSGRP} ${CUPS_SPOOLDIR}
	${CHMOD} -R g+w ${CUPS_SPOOLDIR}
.for f in classes.conf client.conf cupsd.conf printers.conf
	cd ${CUPS_ETCDIR};\
	if test ! -f ${f}.N; then cp -p ${f} ${f}.N; else true; fi
.endfor # classes.conf client.conf cupsd.conf printers.conf

.include "${.CURDIR}/../../print/cups/Makefile.common"
.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>

#EOF
