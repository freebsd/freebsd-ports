# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	mu-conference
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://download.gna.org/mu-conference/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-User Conferencing component for Jabber

LICENSE=	GPLv2

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
		idn:${PORTSDIR}/dns/libidn

USES=		pkgconfig
USE_GNOME=	glib20
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	MYSQL
OPTIONS_DEFAULT=DAEMON
OPTIONS_SINGLE=	SERVER
OPTIONS_SINGLE_SERVER=	JABBER JABBERD EJABBERD DAEMON

JABBER_DESC=	Use with jabberd14 (net-im/jabber)
JABBERD_DESC=	Use with jabberd 2.x (net-im/jabberd)
EJABBERD_DESC=	Use with ejabberd (net-im/ejabberd)
DAEMON_DESC=	Use builtin daemon

SUB_FILES+=	pkg-message README.FreeBSD.jabberd14 \
		README.FreeBSD.jabberd2 README.FreeBSD.external

DOCFILES=	AUTHORS ChangeLog FAQ LICENSE README TODO \
		XEP0045_SUPPORT muc-default.xml style.css

PORTDOCS=	*

MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CFLAGS+=	-DHAVE_MYSQL
LIBS+=		`${LOCALBASE}/bin/mysql_config --libs`
MAKE_ENV+=	LIBS="${LIBS}"
DOCFILES+=	README.sql mu-conference.sql
.endif

MUC_LOGDIR?=	/var/log/mu-conference

.if ${PORT_OPTIONS:MJABBER}
JABBER_REQUIRE?=        jabber
JABBER_USER?=           jabber
JABBER_PIDDIR?=         /var/run/jabberd
JABBER_SPOOLDIR?=       /var/spool/jabberd
RUN_DEPENDS+=           jabberd14:${PORTSDIR}/net-im/jabber
.elif ${PORT_OPTIONS:MJABBERD}
JABBER_REQUIRE?=        jabberd
JABBER_USER?=           jabber
JABBER_PIDDIR?=         /var/jabberd/pid
JABBER_SPOOLDIR?=       /var/spool/jabber
RUN_DEPENDS+=           jabberd:${PORTSDIR}/net-im/jabberd
.elif ${PORT_OPTIONS:MEJABBERD}
JABBER_REQUIRE?=        ejabberd
JABBER_USER?=           ejabberd
JABBER_PIDDIR?=         /var/jabberd/pid
JABBER_SPOOLDIR?=       /var/spool/jabber
RUN_DEPENDS+=           ejabberdctl:${PORTSDIR}/net-im/ejabberd
.elif ${PORT_OPTIONS:MDAEMON}
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
		-e 's#`pkg-config#-I${LOCALBASE}/include `${LOCALBASE}/bin/pkg-config#g' \
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
