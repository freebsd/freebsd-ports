# New ports collection makefile for: avcheck
# Date created:         Fri Jun 14 14:31:42 MSD 2002
# Whom:                 dsh@vlink.ru
#
# $FreeBSD$
#

PORTNAME=	avcheck
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.corpit.ru/ftp/avcheck/

MAINTAINER=	dsh@vlink.ru
COMMENT=	A simple antivirus solution for a mail system

USE_REINPLACE=	yes

MAN1=		avcheck.1

PLIST_FILES=	sbin/avcheck sbin/uchroot
PORTDOCS=	README.AVP README.AVP.de README.DrWeb README.Exim \
		README.Postfix README.Postfix.de README.Sendmail eicar.msg \
		eicar.txt

post-patch:
	@${REINPLACE_CMD} -e 's/^CC/#CC/g ; s/^CFLAGS/#CFLAGS/g' ${WRKSRC}/Makefile

do-install:
.for i in avcheck uchroot
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/sbin/
.endfor

.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${MANPREFIX}/man/man1/
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
