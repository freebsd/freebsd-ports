# New ports collection makefile for:	amavisd-milter
# Date created:		2005-06-08
# Whom:			Petr Rehor <prehor@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	amavisd-milter
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	security mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	prehor@gmail.com
COMMENT=	Milter for amavisd-new

RUN_DEPENDS=	amavisd:${PORTSDIR}/security/amavisd-new

##
# Use the following quirks to choose which sendmail to use (ports or system):
#
#   WITH_SENDMAIL_BASE=yes
# or
#   WITH_SENDMAIL_PORT=yes
#
# If unspecified, check for an up-to-date system version but give an
# installed port preference over it.
##

# Shared defaults with security/amavisd-new
AMAVISUSER?=	vscan
AMAVISDIR?=	/var/amavis

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--localstatedir=${AMAVISDIR} --with-working-dir=tmp
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	AMAVISUSER=${AMAVISUSER} \
		AMAVISDIR=${AMAVISDIR}

PORTDOCS=	AUTHORS CHANGES INSTALL LICENSE README TODO

PLIST_FILES=	sbin/amavisd-milter
PLIST_SUB=	RC_DIR=${RC_DIR} \
		RC_SUFX=${RC_SUFX}

MAN8=		amavisd-milter.8

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_BASE) && !exists(/usr/lib/libmilter.a)
BROKEN=		Base system sendmail not found or too old, rebuild with WITH_SENDMAIL_PORT=yes
.endif

.if !defined(SENDMAIL_WITHOUT_MILTER)
.if defined(WITH_SENDMAIL_PORT)
.if !defined(WITH_SENDMAIL_STATIC_MILTER) && !exists(${LOCALBASE}/lib/libmilter.so.${MILTER_SOVER})
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} You must rebuild sendmail port with SENDMAIL_WITH_SHARED_MILTER
	@${ECHO_MSG} or set variable WITH_SENDMAIL_STATIC_MILTER
	@${FALSE}
.endif
.endif
.endif

.if defined(WITH_SENDMAIL_PORT)
CONFIGURE_ARGS+=--with-sendmail=${MILTERBASE}
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
