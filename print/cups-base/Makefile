# New ports collection makefile for:	cups-base
# Date created:				29 November 2001
# Whom:					James Halstead <jah4007@cs.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	cups-base
PORTVERSION=	${CUPS_PORTVER}
PORTREVISION=	4
CATEGORIES?=	print

MAINTAINER=	alane@FreeBSD.org

INSTALLS_SHLIB=	yes

MAN1=		backend.1 filter.1
MAN3=		cups-config.3
MAN5=		classes.conf.5 cupsd.conf.5 mime.convs.5 mime.types.5 \
		printers.conf.5
MAN8=		cups-lpd.8 cups-polld.8 cupsd.8

post-install:
	@${INSTALL_DATA} ${WRKSRC}/conf/classes.conf \
		${PREFIX}/etc/cups/classes.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/client.conf \
		${PREFIX}/etc/cups/client.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/cupsd.conf \
		${PREFIX}/etc/cups/cupsd.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/printers.conf \
		${PREFIX}/etc/cups/printers.conf.sample
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/cups.sh \
		${PREFIX}/etc/rc.d/cupsd.sh.sample
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include "${.CURDIR}/../../print/cups/Makefile.inc"
.include <bsd.port.mk>
