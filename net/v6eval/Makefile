# Created by: TANAKA Takashi <tanaka@tahi.org>
# $FreeBSD$

PORTNAME=	v6eval
PORTVERSION=	3.3.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tahi.org/release/v6eval/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPv6 Conformance Test Platform

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

RUN_DEPENDS=	p5-Expect>=0:${PORTSDIR}/lang/p5-Expect \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USE_PERL5=	yes
USE_OPENSSL=	yes
USES=	shebangfix
SHEBANG_FILES=	\
	bin/autorun/autorun.pl \
	bin/indexgen/indexgen.pl \
	bin/pktbuf/pktbuf.pl \
	bin/pktctl/pktctl.pl \
	bin/pktlint/pktlint.pl \
	bin/pktrecv/pktrecv.pl \
	bin/pktsend/pktsend.pl \
	bin/remotes/manual/cleardefr.rmt \
	bin/remotes/manual/clearmtu.rmt \
	bin/remotes/manual/clearnc.rmt \
	bin/remotes/manual/clearprefix.rmt \
	bin/remotes/manual/clearroute.rmt \
	bin/remotes/manual/dhcp6c.rmt \
	bin/remotes/manual/dhcp6r.rmt \
	bin/remotes/manual/dhcp6s.rmt \
	bin/remotes/manual/igmpv3.rmt \
	bin/remotes/manual/igmpv3config.rmt \
	bin/remotes/manual/ikeClearAll.rmt \
	bin/remotes/manual/ikeConfig.rmt \
	bin/remotes/manual/ikeDump.rmt \
	bin/remotes/manual/ikeEnable.rmt \
	bin/remotes/manual/ikeInitiate.rmt \
	bin/remotes/manual/ikeResetSA.rmt \
	bin/remotes/manual/ikeSetSA.rmt \
	bin/remotes/manual/ikeStart.rmt \
	bin/remotes/manual/ikeStop.rmt \
	bin/remotes/manual/ikeTunnel.rmt \
	bin/remotes/manual/ipsecClearAll.rmt \
	bin/remotes/manual/ipsecEnable.rmt \
	bin/remotes/manual/ipsecResetSPD.rmt \
	bin/remotes/manual/ipsecSetSAD.rmt \
	bin/remotes/manual/ipsecSetSPD.rmt \
	bin/remotes/manual/loginout.rmt \
	bin/remotes/manual/manualaddrconf.rmt \
	bin/remotes/manual/mip6EnableCN.rmt \
	bin/remotes/manual/mip6EnableHA.rmt \
	bin/remotes/manual/mip6EnableMN.rmt \
	bin/remotes/manual/mldv2.rmt \
	bin/remotes/manual/mldv2DisableHUT.rmt \
	bin/remotes/manual/mldv2DisableRUT.rmt \
	bin/remotes/manual/mldv2EnableHUT.rmt \
	bin/remotes/manual/mldv2EnableRUT.rmt \
	bin/remotes/manual/mldv2ListenerAPI.rmt \
	bin/remotes/manual/mldv2SetHUT.rmt \
	bin/remotes/manual/mldv2SetRUT.rmt \
	bin/remotes/manual/mldv2config.rmt \
	bin/remotes/manual/mtuconfig.rmt \
	bin/remotes/manual/multicastConfig.rmt \
	bin/remotes/manual/natpt.rmt \
	bin/remotes/manual/pim6dd.rmt \
	bin/remotes/manual/ping6.rmt \
	bin/remotes/manual/racontrol.rmt \
	bin/remotes/manual/reboot.rmt \
	bin/remotes/manual/reboot_async.rmt \
	bin/remotes/manual/ripng_start.rmt \
	bin/remotes/manual/ripng_stop.rmt \
	bin/remotes/manual/route.rmt \
	bin/remotes/manual/rtadvd.rmt \
	bin/remotes/manual/setDNS.rmt \
	bin/remotes/manual/showAddr.rmt \
	bin/remotes/manual/sysctl.rmt \
	bin/remotes/manual/tcp6.rmt \
	bin/remotes/manual/tunnel.rmt \
	bin/remotes/manual/useTempAddr.rmt \
	bin/remotes/unknown/cleardefr.rmt \
	bin/remotes/unknown/clearmtu.rmt \
	bin/remotes/unknown/clearnc.rmt \
	bin/remotes/unknown/clearprefix.rmt \
	bin/remotes/unknown/clearroute.rmt \
	bin/remotes/unknown/dhcp6c.rmt \
	bin/remotes/unknown/dhcp6r.rmt \
	bin/remotes/unknown/dhcp6s.rmt \
	bin/remotes/unknown/igmpv3.rmt \
	bin/remotes/unknown/igmpv3config.rmt \
	bin/remotes/unknown/ikeClearAll.rmt \
	bin/remotes/unknown/ikeConfig.rmt \
	bin/remotes/unknown/ikeDump.rmt \
	bin/remotes/unknown/ikeEnable.rmt \
	bin/remotes/unknown/ikeInitiate.rmt \
	bin/remotes/unknown/ikeResetSA.rmt \
	bin/remotes/unknown/ikeSetSA.rmt \
	bin/remotes/unknown/ikeStart.rmt \
	bin/remotes/unknown/ikeStop.rmt \
	bin/remotes/unknown/ikeTunnel.rmt \
	bin/remotes/unknown/ipsecClearAll.rmt \
	bin/remotes/unknown/ipsecEnable.rmt \
	bin/remotes/unknown/ipsecResetSPD.rmt \
	bin/remotes/unknown/ipsecSetSAD.rmt \
	bin/remotes/unknown/ipsecSetSPD.rmt \
	bin/remotes/unknown/loginout.rmt \
	bin/remotes/unknown/manualaddrconf.rmt \
	bin/remotes/unknown/mip6EnableCN.rmt \
	bin/remotes/unknown/mip6EnableHA.rmt \
	bin/remotes/unknown/mip6EnableMN.rmt \
	bin/remotes/unknown/mldv2.rmt \
	bin/remotes/unknown/mldv2config.rmt \
	bin/remotes/unknown/mtuconfig.rmt \
	bin/remotes/unknown/multicastConfig.rmt \
	bin/remotes/unknown/natpt.rmt \
	bin/remotes/unknown/pim6dd.rmt \
	bin/remotes/unknown/ping6.rmt \
	bin/remotes/unknown/racontrol.rmt \
	bin/remotes/unknown/reboot.rmt \
	bin/remotes/unknown/ripng_start.rmt \
	bin/remotes/unknown/ripng_stop.rmt \
	bin/remotes/unknown/reboot_async.rmt \
	bin/remotes/unknown/route.rmt \
	bin/remotes/unknown/rtadvd.rmt \
	bin/remotes/unknown/setDNS.rmt \
	bin/remotes/unknown/showAddr.rmt \
	bin/remotes/unknown/sysctl.rmt \
	bin/remotes/unknown/tcp6.rmt \
	bin/remotes/unknown/tunnel.rmt \
	bin/remotes/unknown/useTempAddr.rmt \
	sample/64tunnel_ll_ping/ping.seq \
	sample/HBHoptAfterDstOpt/HBHoptAfterDstOpt.seq \
	sample/jumbo/jumbo.seq \
	sample/mld-general/mld-general.seq \
	sample/na_w_mtu/na_w_mtu.seq \
	sample/ping/ping.seq \
	sample/ping4/ping4.seq \
	sample/ping_frag/ping_frag.seq \
	sample/ping_from_many_host/ping.seq \
	sample/ping_glosite/ping_glosite.seq \
	sample/ping_w_ah/ping.seq \
	sample/ping_w_ahesp/ping.seq \
	sample/ping_w_esp/ping.seq \
	sample/ping_w_espicv/ping.seq \
	sample/ping_w_espicvespicv/ping.seq \
	sample/portunreach/portunreach.seq \
	sample/redirect/redirect.seq \
	sample/timeexceeded/timeexceeded.seq \
	sample/udpecho/udpecho.seq \
	sample/unknownnext/unknownnext.seq \
	sample_stddef/SendRecv/Recv.seq \
	sample_stddef/SendRecv/Send.seq \
	sample_stddef/aes-ctr/aes-ctr.seq \
	sample_stddef/igmp/igmpv3_test.seq \
	sample_stddef/mldv2/mldv2_test.seq \
	sample_stddef/ping_frag/ping_frag.seq \
	sample_stddef/ping_glosite/ping_glosite.seq \
	sample_stddef/snmp/snmp.seq \
	sample_stddef/tcp_handshake/tcp_handshake.seq \
	script/pmod/V6evalRemote/sample/reboot.rmt \
	script/pmod/V6evalRemote/sample/ls.rmt \
	script/pmod/V6evalRemote/sample/reboot_async.rmt \
	script/pmod/V6evalRemote/V6evalRemote.pm \
	script/pmod/V6evalTool/V6evalTool.pm
MAKE_ENV=	PREFIX="${PREFIX}" \
		BSD_INSTALL_DATA="${BSD_INSTALL_DATA}" \
		BSD_INSTALL_SCRIPT="${BSD_INSTALL_SCRIPT}"
SUB_FILES=	pkg-message

NO_MANCOMPRESS=	yes
MAN1PREFIX=	${PREFIX}/v6eval
MAN3PREFIX=	${LOCALBASE}/lib/perl5/${PERL_VER}
MAN1=		pktctl.1.gz pktsend.1.gz
MAN3=		V6evalRemote.3 V6evalTool.3

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/script/pmod/V6evalCommon/V6evalCommon.pm

post-install:
	${FIND} ${WRKSRC}/sample ${WRKSRC}/sample_stddef \
	    -name "*.orig" -a -exec ${RM} -f "{}" \;
	cd ${WRKSRC} && ${COPYTREE_SHARE} sample ${PREFIX}/v6eval
	cd ${WRKSRC} && ${COPYTREE_SHARE} sample_stddef ${PREFIX}/v6eval
	cd ${PREFIX}/v6eval && ${CHMOD} +x ${SHEBANG_FILES:Msample*}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
