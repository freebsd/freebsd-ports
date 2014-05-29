# Created by: gnn
# $FreeBSD$

# XXX: TODO: fix kernel module

PORTNAME=	click
PORTVERSION=	1.5.0
CATEGORIES=	net
MASTER_SITES=	http://www.read.cs.ucla.edu/click/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Click Modular Router

USES=		perl5 gmake
USE_PERL5=	build
GNU_CONFIGURE=	yes

INC_BASE?=	/usr/include

CONFIGURE_ARGS+=	--disable-linuxmodule
CONFIGURE_ARGS+=	--enable-nanotimestamp

MANCOMPRESSED=	no
INFO=	click
MAN1=	click.1 click-align.1 click-combine.1 click-devirtualize.1 \
	click-fastclassifier.1 click-flatten.1 click-install.1 \
	click-mkmindriver.1 click-pretty.1 click-uncombine.1 click-undead.1 \
	click-uninstall.1 click-xform.1 testie.1
MAN5=	click.5
MAN7=	elementdoc.7
MAN8=	click.o.8
MANN=	FTPPortMapper.n ARPFaker.n ARPPrint.n ARPQuerier.n ARPResponder.n \
	elements-click.n ChangeUID.n \
	EnsureEther.n EtherEncap.n EtherMirror.n HostEtherFilter.n \
	CheckARPHeader.n DirectIPLookup.n \
	RFC2507Comp.n RFC2507Decomp.n \
	CheckICMPHeader.n ICMPError.n ICMPPingResponder.n ICMPPingRewriter.n \
	ICMPRewriter.n CheckIPHeader.n CheckIPHeader2.n \
	DecIPTTL.n FixIPSrc.n FromSocket.n GetIPAddress.n ICMPPingEncap.n \
	ICMPPingSource.n IPAddrRewriter.n IPAddrPairRewriter.n IPClassifier.n \
	IPEncap.n IPFilter.n IPFragmenter.n IPGWOptions.n IPInputCombo.n \
	IPNameInfo.n \
	IPMirror.n IPOutputCombo.n IPPrint.n IPRateMonitor.n IPRewriterPatterns.n \
	KernelTun.n LinearIPLookup.n LinkUnqueue.n \
	MarkIPCE.n MarkIPHeader.n Message.n MixedQueue.n NotifierQueue.n \
	PaintSwitch.n PortInfo.n RIPSend.n RandomSwitch.n RangeIPLookup.n \
	RoundRobinIPMapper.n SetAnnoByte.n SetIPAddress.n SetIPChecksum.n SetIPDSCP.n \
	SetRandIPAddress.n SetUDPChecksum.n SimpleQueue.n StoreData.n \
	StoreIPAddress.n StripIPHeader.n ToSocket.n UnstripIPHeader.n \
	Socket.n Script.n Truncate.n \
	AddressInfo.n Align.n AlignmentInfo.n AverageCounter.n \
	BandwidthMeter.n BandwidthShaper.n Burster.n BandwidthRatedSplitter.n \
	BandwidthRatedUnqueue.n CheckCRC32.n CheckLength.n CheckPaint.n \
	Classifier.n CompareBlock.n Counter.n DelayShaper.n DelayUnqueue.n \
	Discard.n DiscardNoFree.n DriverManager.n DropBroadcasts.n DRRSched.n \
	Error.n FrontDropQueue.n HashSwitch.n Idle.n \
	InfiniteSource.n Meter.n MSQueue.n Null.n PushNull.n PullNull.n \
	Null1.n \
	Paint.n PaintTee.n PokeHandlers.n Print.n PrioSched.n \
	PullSwitch.n Queue.n QuitWatcher.n \
	RandomBitErrors.n RandomSource.n RatedSource.n \
	RatedSplitter.n RatedUnqueue.n RED.n RoundRobinSched.n \
	RoundRobinSwitch.n ScheduleInfo.n SetCRC32.n SetTimestamp.n Shaper.n \
	SourceIPHashMapper.n SortedIPLookup.n \
	SpinlockAcquire.n SpinlockInfo.n SpinlockRelease.n StaticPullSwitch.n \
	StaticSwitch.n StrideSched.n StrideSwitch.n Strip.n Suppressor.n \
	Switch.n Tee.n PullTee.n TimedSink.n TimedSource.n Unqueue.n \
	Unqueue2.n Unstrip.n CheckTCPHeader.n CheckUDPHeader.n \
	DynamicUDPIPEncap.n IPRewriter.n SetTCPChecksum.n TCPRewriter.n \
	UDPIPEncap.n ChatterSocket.n ControlSocket.n FromDevice.u.n \
	FromDump.n KernelTap.n KernelHandlerProxy.n \
	ToDevice.u.n ToDump.n elements.n AdaptiveRED.n IPReassembler.n \
	IPRouteTable.n StaticIPLookup.n LinuxIPLookup.n RadixIPLookup.n \
	RandomSample.n SetPacketType.n StripToNetworkHeader.n ProgressBar.n

CONFDIR=	${PREFIX}/etc/click/conf

OPTIONS_DEFINE=		ANALYSIS_ELEMS ETHERSWITCH_ELEMS GRID_ELEMS \
			IPSEC_ELEMS IPV6_ELEMS KERNEL_MODULE LOCAL_ELEMS \
			NS_ELEMS RADIO_ELEMS USERCLICK WIFI_ELEMS XML_EXPAT
OPTIONS_DEFAULT=	USERCLICK
ANALYSIS_ELEMS_DESC=	Build network analysis elements
ETHERSWITCH_ELEMS_DESC=	Build etherswitch elements
GRID_ELEMS_DESC=	Build Grid elements (see FAQ)
IPSEC_ELEMS_DESC=	Build IPSEC elements
IPV6_ELEMS_DESC=	Build IPv6 elements (EXPERIMENTAL)
KERNEL_MODULE_DESC=	Build BSD kernel module (BROKEN)
LOCAL_ELEMS_DESC=	Build local elements
NS_ELEMS_DESC=		Build NS elements (EXPERIMENTAL)
RADIO_ELEMS_DESC=	Build radio elements (EXPERIMENTAL)
USERCLICK_DESC=		Build user-space Click
WIFI_ELEMS_DESC=	Build Wi-Fi elements
XML_EXPAT_DESC=		Enable XML support with expat

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXML_EXPAT}
CONFIGURE_ARGS+=	--with-expat=${LOCALBASE}
LIB_DEPENDS=		expat.6:${PORTSDIR}/textproc/expat2
PLIST_SUB+=		XMLCLICK=""
.else
PLIST_SUB+=		XMLCLICK="@comment "
.endif

.if !${PORT_OPTIONS:MUSERCLICK}
CONFIGURE_ARGS+=	--disable-userlevel
#.else
#MANN+=			IPFlowRawSockets.n
.endif

.if ${PORT_OPTIONS:MKERNEL_MODULE}
.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		kernel source files required
.endif
CONFIGURE_ARGS+=	--enable-bsdmodule				\
			--with-freebsd=${SRC_BASE}/sys,${INC_BASE}
.else
CONFIGURE_ARGS+=	--disable-bsdmodule
.endif

.if ${PORT_OPTIONS:MANALYSIS_ELEMS}
CONFIGURE_ARGS+=	--enable-analysis
MANN+=		AggregateFilter.n TimeSortedSched.n TimeRange.n \
		FromTcpdump.n ToIPFlowDumps.n AggregateLast.n \
		SimPacketAnalyzer.n AggregatePaint.n \
		FromNetFlowSummaryDump.n AggregateFirst.n AggregateCounter.n \
		FromDAGDump.n StoreTimestamp.n AggregateIPFlows.n \
		SetTimestampDelta.n FromCapDump.n AggregateIP.n \
		TimestampAccum.n AnonymizeIPAddr.n AggregateLength.n \
		FromIPSummaryDump.n ToIPSummaryDump.n AggregateIPAddrPair.n \
		AggregatePacketCounter.n TimeFilter.n
.endif

.if ${PORT_OPTIONS:METHERSWITCH_ELEMS}
CONFIGURE_ARGS+=	--enable-etherswitch
MANN+=			EtherSwitch.n ListenEtherSwitch.n
.endif

.if ${PORT_OPTIONS:MGRID_ELEMS}
CONFIGURE_ARGS+=	--enable-grid
MANN+=		ACKResponder.n ACKResponder2.n ACKRetrySender.n \
		ACKRetrySender2.n AiroInfo.n BottleneckMetric.n \
		CheckGridHeader.n DSDVRouteTable.n DSRArpTable.n \
		DSRRouteTable.n E2ELossMetric.n ETX2Metric.n ETXMetric.n \
		EstimateRouterRegion.n FilterByGridHops.n FilterByRange.n \
		FixDstLoc.n FixSrcLoc.n FloodingLocQuerier.n FromNLANRDump.n \
		GridEncap.n GridGatewayInfo.n GridHeaderInfo.n \
		GridLocationInfo.n GridLocationInfo2.n GridLogger.n \
		GridProbeHandler.n GridProbeReplyReceiver.n \
		GridProbeSender.n GridProxy.n GridRouteTable.n GridTxError.n \
		HopcountMetric.n IncrementSeqNo.n LIRMetric.n LinkStat.n \
		LinkTable.n LinkTestReceiver.n LinkTester.n LinkTracker.n \
		LocFromFile.n LocQueryResponder.n LocationTable.n \
		LookupGeographicGridRoute.n LookupLocalGridRoute.n \
		LookupLocalGridRoute2.n MovementSimulator.n PEP.n \
		PacketLogger.n PacketLogger2.n PingPong.n PrintGrid.n \
		SendGridHello.n SendGridLRHello.n SetGridChecksum.n \
		SimpleLocQuerier.n ThresholdMetric.n UpdateGridRoutes.n \
		YarvisMetric.n
.endif

.if ${PORT_OPTIONS:MIPSEC_ELEMS}
CONFIGURE_ARGS+=	--enable-ipsec
MANN+=			IPsecAuthSHA1.n IPsecDES.n IPsecESPUnencap.n \
			IPsecESPEncap.n
.endif

.if ${PORT_OPTIONS:MLOCAL_ELEMS}
CONFIGURE_ARGS+=	--enable-local
.endif

.if ${PORT_OPTIONS:MWIFI_ELEMS}
CONFIGURE_ARGS+=	--enable-wifi
MANN+=		FilterPhyErr.n AssociationResponder.n FilterFailures.n \
		ReadAnno.n PacketStore.n AvailableRates.n \
		AssociationRequester.n OpenAuthResponder.n \
		OpenAuthRequeser.n Prism2Encap.n ProbeResponder.n \
		AutoRateFallback.n ProbeTXRate.n ARPTable.n WepEncap.n \
		WepDecap.n WifiDecap.n FilterTX.n EtherCount.n \
		RadiotapDecap.n RadiotapEncap.n WifiFragment.n \
		BeaconSource.n BeaconTracker.n BeaconScanner.n RXStats.n \
		WirelessInfo.n PrintTXFeedback.n SetTXRate.n SetTXPower.n \
		Prism2Decap.n WifiEncap.n WifiDefrag.n MadwifiRate.n \
		PrintWifi.n WifiSeq.n PushAnno.n WifiDupeFilter.n \
		ExtraEncap.n ExtraDecap.n AthdescDecap.n AthdescEncap.n
.endif

#
# The following Click elements are marked experimental as of 1.5.0.
#

.if ${PORT_OPTIONS:MIPV6_ELEMS}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${PORT_OPTIONS:MNS_ELEMS}
CONFIGURE_ARGS+=	--enable-nsclick
MANN+=			ToSimTrace.n ToSimDevice.u.n FromSimDevice.u.n \
			EraseIPPayload.n
PLIST_SUB+=		NSCLICK=""
.else
PLIST_SUB+=		NSCLICK="@comment "
.endif

.if ${PORT_OPTIONS:MRADIO_ELEMS}
CONFIGURE_ARGS+=	--enable-radio
MANN+=			RadioSim.n
.endif

post-install:
	cd ${PREFIX}/bin && ${STRIP_CMD} click click-align click-check \
	  click-combine click-uncombine click-devirtualize click-fastclassifier \
	  click-flatten click-mkmindriver click-undead click-xform
	@${MKDIR} ${CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/*.click ${CONFDIR}
	@${MKDIR} ${CONFDIR}/wifi
	${INSTALL_DATA} ${WRKSRC}/conf/wifi/*.click ${CONFDIR}/wifi
	@${ECHO_CMD}
	@${ECHO_CMD} "----------------------------------------------------"
	@${ECHO_CMD} "Install complete, to try it out do the following:"
	@${ECHO_CMD} "cd ${PREFIX}/etc/click/conf"
	@${ECHO_CMD} "click test.click"
	@${ECHO_CMD} "You should see some output.  Now go read the papers and manual."
	@${ECHO_CMD} "----------------------------------------------------"
	@${ECHO_CMD}

.include <bsd.port.mk>
