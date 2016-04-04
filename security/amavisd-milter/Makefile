# Created by: Petr Rehor <rx@rx.cz>
# $FreeBSD$

PORTNAME=	amavisd-milter
PORTVERSION=	1.6.0
PORTREVISION=	4
CATEGORIES=	security mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rx@rx.cz
COMMENT=	Milter for amavisd-new

RUN_DEPENDS=	amavisd:security/amavisd-new

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
AMAVISGROUP?=	vscan
AMAVISDIR?=	/var/amavis

RUNDIR=		/var/run/amavis

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${RUNDIR} --with-working-dir=${AMAVISDIR}/tmp
USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	AMAVISUSER=${AMAVISUSER} \
		AMAVISGROUP=${AMAVISGROUP} \
		AMAVISDIR=${AMAVISDIR} \
		RUNDIR=${RUNDIR}
PLIST_SUB=	${SUB_LIST}

PORTDOCS=	AUTHORS CHANGES INSTALL LICENSE README TODO

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_BASE) && !exists(/usr/lib/libmilter.a)
BROKEN=		Base system sendmail not found or too old, rebuild with WITH_SENDMAIL_PORT=yes
.endif

.if defined(WITH_SENDMAIL_PORT)
CONFIGURE_ARGS+=--with-sendmail=${MILTERBASE}
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL} -d -o ${AMAVISUSER} -g ${AMAVISGROUP} -m 755 ${STAGEDIR}${RUNDIR}

.include <bsd.port.post.mk>
