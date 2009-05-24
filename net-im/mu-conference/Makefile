# New ports collection makefile for:	mu-conference
# Date created:			Mon Feb  9 15:34:59 MSK 2004
# Whom:				Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$

PORTNAME=	mu-conference
PORTVERSION=	0.8
CATEGORIES=	net-im
MASTER_SITES=	http://download.gna.org/mu-conference/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Multi-User Conferencing component for Jabber

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		idn.16:${PORTSDIR}/dns/libidn

USE_GNOME=	glib20 pkgconfig
USE_RC_SUBR=	${PORTNAME}

OPTIONS=	MYSQL "Enable MySQL support" off \
		JABBER "Use with jabberd14 (net-im/jabber)" off \
		JABBERD "Use with jabberd 2.x (net-im/jabberd)" off \
		EJABBERD "Use with ejabberd (net-im/ejabberd)" off

SUB_FILES+=	pkg-message README.FreeBSD.jabberd14 \
		README.FreeBSD.jabberd2 README.FreeBSD.external

CFLAGS+=	-I${LOCALBASE}/include

DOCFILES=	AUTHORS COPYING ChangeLog FAQ LICENSE README TODO \
		XEP0045_SUPPORT muc-default.xml style.css

PORTDOCS=	*

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CFLAGS+=	-DHAVE_MYSQL
LIBS+=		`${LOCALBASE}/bin/mysql_config --libs`
MAKE_ENV+=	LIBS="${LIBS}"
DOCFILES+=	README.sql mu-conference.sql
.endif

MUC_LOGDIR?=	/var/log/mu-conference

.if defined(WITH_JABBER)
JABBER_REQUIRE?=        jabber
JABBER_USER?=           jabber
JABBER_PIDDIR?=         /var/run/jabberd
JABBER_SPOOLDIR?=       /var/spool/jabberd
RUN_DEPENDS+=           jabberd14:${PORTSDIR}/net-im/jabber
.elif defined(WITH_JABBERD)
JABBER_REQUIRE?=        jabberd
JABBER_USER?=           jabber
JABBER_PIDDIR?=         /var/jabberd/pid
JABBER_SPOOLDIR?=       /var/spool/jabber
RUN_DEPENDS+=           jabberd:${PORTSDIR}/net-im/jabberd
.elif defined(WITH_EJABBERD)
JABBER_REQUIRE?=        ejabberd
JABBER_USER?=           ejabberd
JABBER_PIDDIR?=         /var/jabberd/pid
JABBER_SPOOLDIR?=       /var/spool/jabber
RUN_DEPENDS+=           ejabberd:${PORTSDIR}/net-im/ejabberdctl
.else
JABBER_REQUIRE?=        DAEMON
JABBER_USER?=           nobody
JABBER_PIDDIR?=         /var/run/mu-conference
JABBER_SPOOLDIR?=       /var/spool/mu-conference
.endif

SUB_LIST+=	JABBER_REQUIRE="${JABBER_REQUIRE}" \
		JABBER_PIDDIR="${JABBER_PIDDIR}" \
		JABBER_SPOOLDIR="${JABBER_SPOOLDIR}" \
		JABBER_USER=${JABBER_USER} \
		MUC_LOGDIR=${MUC_LOGDIR}

post-patch:
	@${REINPLACE_CMD} -e 's/=$$(CFLAGS)/=/g;s/^CFLAGS[:]*=/CFLAGS+=/g' \
		-e 's/^CC:*=/CC?=/g;s|gcc |$$(CC) |;s|-O2||g' \
		-e 's#`pkg-config#`${LOCALBASE}/bin/pkg-config#g' \
		${WRKSRC}/Makefile ${WRKSRC}/*/Makefile \
		${WRKSRC}/*/*/Makefile
	@${REINPLACE_CMD} -e 's#<spool>\./spool/chat.localhost#<spool>${JABBER_SPOOLDIR}/conference.localhost#g' \
		-e 's#<logdir>\./syslogs#<logdir>${LOGDIR}#g' \
		-e 's#<logdir>\./logs#<logdir>${JABBER_SPOOLDIR}/conference.localhost/logs#g' \
		-e 's#<pidfile>\.#<pidfile>${JABBER_PIDDIR}#g' \
		${WRKSRC}/muc-default.xml

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mu-conference ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/muc-default.xml ${PREFIX}/etc/muc.xml.sample
	@if ! [ -f ${PREFIX}/etc/muc.xml ]; then \
		${INSTALL_DATA} ${WRKSRC}/muc-default.xml ${PREFIX}/etc/muc.xml; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/scripts
.for FILE in README.FreeBSD.jabberd14 README.FreeBSD.jabberd2 README.FreeBSD.external
	@${INSTALL_DATA} ${WRKDIR}/${FILE} ${DOCSDIR}
.endfor
.for FILE in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/scripts/README ${DOCSDIR}/scripts
.for FILE in roommaker.pl roomname.pl
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${FILE} ${DOCSDIR}/scripts
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
