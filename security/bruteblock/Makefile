# New ports collection makefile for:	bruteblock
# Date created:		30 Jul 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	bruteblock
PORTVERSION=	0.0.4
CATEGORIES=	security
MASTER_SITES=	http://samm.kiev.ua/bruteblock/

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Software for blocking bruteforce attacks with ipfw

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

USE_RC_SUBR=	bruteblockd.sh
MAN8=		bruteblock.8

CONFDIR=	${PREFIX}/etc/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		requires FreeBSD >= 5.3
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bruteblock ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/bruteblockd ${PREFIX}/sbin/
	${MKDIR} ${PREFIX}/etc/bruteblock
.for file in ssh	# more configs are planned to be added
	${INSTALL_DATA} ${WRKSRC}/etc/${file}.conf ${CONFDIR}/${file}.conf.dist
	if [ ! -f ${CONFDIR}/${file}.conf ]; then \
		${INSTALL_DATA} ${CONFDIR}/${file}.conf.dist ${CONFDIR}/${file}.conf; \
	fi
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/bruteblock.8 ${PREFIX}/man/man8/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
