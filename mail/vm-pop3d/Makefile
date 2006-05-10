# New ports collection makefile for:	vm-pop3d
# Date created:			24 August 2001
# Whom:				Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	vm-pop3d
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SUNSITE}	\
		http://www.ibiblio.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	system/mail/pop

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A virtual POP3 server

GNU_CONFIGURE=	yes

.if defined(WITH_IPVIRTUAL)
CONFIGURE_ARGS+=	--enable-ip-based-virtual --enable-virtual
.elif defined(WITH_VIRTUAL)
CONFIGURE_ARGS+=	--enable-virtual
.endif

MAN8=		vm-pop3d.8

DOCS=		AUTHORS CHANGES COPYING FAQ INSTALL README

pre-patch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_VIRTUAL	enable virtual passwd files and spool directories."
	@${ECHO} "	WITH_IPVIRTUAL	enable IP-based virtual passwd files and spool directories."
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} -e "s@LIBS -ldl@LIBS@" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/vm-pop3d.h
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${FILESDIR}/vm-pop3d.sh > ${WRKSRC}/vm-pop3d.sh.sample

post-install:
	${INSTALL_MAN} ${WRKSRC}/vm-pop3d.8 ${MAN8PREFIX}/man/man8
	${INSTALL_SCRIPT} ${WRKSRC}/vm-pop3d.sh.sample ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO} "Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
