# Created by: dsh@vlink.ru
# $FreeBSD$

PORTNAME=	avcheck
PORTVERSION=	0.91
CATEGORIES=	security
MASTER_SITES=	http://www.corpit.ru/ftp/avcheck/

MAINTAINER=	dsh@vlink.ru
COMMENT=	Simple antivirus solution for a mail system

MAN1=		avcheck.1

PLIST_FILES=	sbin/avcheck sbin/uchroot
PORTDOCS=	README.AVP README.AVP.de README.DrWeb README.Exim \
		README.Postfix README.Postfix.de README.Sendmail eicar.msg \
		eicar.txt

NO_STAGE=	yes
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc: drops core
.endif

.include <bsd.port.post.mk>
