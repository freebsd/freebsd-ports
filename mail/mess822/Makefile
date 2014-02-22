# Created by: David Siebörger <drs@rucus.ru.ac.za>
# $FreeBSD$

PORTNAME=	mess822
PORTVERSION=	0.58
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/ \
		ftp://ftp.jp.qmail.org/qmail/ \
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/ \
		ftp://mirror.pipex.net/pub/unix/mail/qmail/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	RFC 822 mail message parsing library and rewriting utilities

USES=		qmail:vars

ALL_TARGET=	it
INSTALL_TARGET=	setup check

NO_MTREE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|.var.qmail|${QMAIL_PREFIX}|" ${WRKSRC}/conf-qmail
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-home

pre-install:
	@${MV} -f ${WRKSRC}/conf-home ${WRKSRC}/conf-home.sav
	@echo "${STAGEDIR}${PREFIX}" > ${WRKSRC}/conf-home
	@cd ${WRKSRC} ; ${RM} -f install instcheck install.o instcheck.o hier.o auto_home.o
	@cd ${WRKSRC} ; ${MAKE_CMD} install instcheck
	@${MV} -f ${WRKSRC}/conf-home.sav ${WRKSRC}/conf-home

.include <bsd.port.mk>
