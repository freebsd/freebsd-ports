# New ports collection makefile for:	gslin
# Date created:			24 August 2001
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	vm-pop3d
PORTVERSION=	1.1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/mail/pop

MAINTAINER=	gslin@ccca.nctu.edu.tw

GNU_CONFIGURE=	yes

.if defined(WITH_IPVIRTUAL)
CONFIGURE_ARGS+=	--enable-ip-based-virtual
.endif

MAN8=		vm-pop3d.8

DOCS=		AUTHORS CHANGES COPYING FAQ INSTALL README

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_IPVIRTUAL	enable IP-based virtual passwd files and spool directories."
	@${ECHO} ""

post-patch:
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/vm-pop3d.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/vm-pop3d.8 ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO} "Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
