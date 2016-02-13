# Created by: Janne Snabb <snabb@epipe.com>
# $FreeBSD$

PORTNAME=	scam-backscatter
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.elandsys.com/scam/scam-backscatter/ \
		http://dist.epipe.com/mirrors/scam-backscatter/
DISTNAME=	scamback-${PORTVERSION}

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/License

MAINTAINER=	snabb@epipe.com
COMMENT=	Address verification milter to prevent spam backscatter

USES=		tar:tgz
WRKSRC=		${WRKDIR}/scamback
USE_RC_SUBR=	scam-backscatter
SUB_FILES=	pkg-message

MAKEFILE=	Makefile.freebsd
ALL_TARGET=	# empty

OPTIONS_DEFINE=	ALLDOMAINS EHLO USEMAILERTABLE DOCS
ALLDOMAINS_DESC=	Verify any domain with the backend
EHLO_DESC=		Use EHLO instead of HELO in SMTP session
USEMAILERTABLE_DESC=	Use mailertable to map domains to backends

.include <bsd.port.options.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

LDFLAGS+=	${SENDMAIL_LDFLAGS}
LIBS+=		-lmilter -lpthread
LIBS+=		${SENDMAIL_LDADD}

.if ${PORT_OPTIONS:MALLDOMAINS}
CFLAGS+=	-DALLDOMAINS
.endif
.if ${PORT_OPTIONS:MEHLO}
CFLAGS+=	-DEHLO
.endif
.if ${PORT_OPTIONS:MUSEMAILERTABLE}
CFLAGS+=	-DUSEMAILERTABLE
.endif

MAKE_ARGS+=	CC="${CC}" CCFLAGS="${CFLAGS}" CFLAGS="" \
		LDFLAGS="${LDFLAGS}" LIBS="${LIBS}"

post-patch:
	@${REINPLACE_CMD} -e \
	    's|/var/spool/scam/scam-back\.pid|/var/run/scam-back\.pid|g; \
	    s|/etc/mail/scam\.conf|${PREFIX}/etc/mail/scam-back\.conf|g;' \
	    ${WRKSRC}/scam-back.c

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_PROGRAM} ${WRKSRC}/scam-back ${STAGEDIR}${PREFIX}/libexec/scam-back
	${INSTALL_DATA} ${WRKSRC}/scam.conf ${STAGEDIR}${PREFIX}/etc/mail/scam-back.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/License ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
