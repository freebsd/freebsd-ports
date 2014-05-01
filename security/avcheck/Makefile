# Created by: dsh@vlink.ru
# $FreeBSD$

PORTNAME=	avcheck
PORTVERSION=	0.91
CATEGORIES=	security
MASTER_SITES=	http://www.corpit.ru/ftp/avcheck/

MAINTAINER=	dsh@vlink.ru
COMMENT=	Simple antivirus solution for a mail system

PLIST_FILES=	man/man1/avcheck.1.gz sbin/avcheck sbin/uchroot
PORTDOCS=	README.AVP README.AVP.de README.DrWeb README.Exim \
		README.Postfix README.Postfix.de README.Sendmail eicar.msg \
		eicar.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/^CC/#CC/g ; s/^CFLAGS/#CFLAGS/g' ${WRKSRC}/Makefile

do-install:
.for i in avcheck uchroot
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/sbin/
.endfor

	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc: drops core
.endif

.include <bsd.port.post.mk>
