---agent/mibgroup/mibII/tcpTable.c.orig	FriJul1821:10:092003
+++agent/mibgroup/mibII/tcpTable.c	FriJul1821:10:122003
@@-435,11+435,42@@
intTCP_Count_Connections(void)
{
	intEstablished;
+#if!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))
+	intmib[4],len;
+	char*p;
+	structtcpcb*tpcb;
+	structxtcpcb*tp;
+	structxinpgen*next;
+
+	mib[0]=CTL_NET;
+	mib[1]=PF_INET;
+	mib[2]=IPPROTO_TCP;
+	mib[3]=TCPCTL_PCBLIST;
+
+	if(sysctl(mib,4,NULL,&len,NULL,0)!=0){
+		snmp_log_perror("TCP_Count_Connections-sysctl");
+		return0;
+	}
+	if((p=(char*)malloc(len))==NULL){
+		snmp_log_perror("TCP_Count_Connections-malloc");
+		return0;
+	}
+	if(sysctl(mib,4,p,&len,NULL,0)!=0){
+		snmp_log_perror("TCP_Count_Connections-sysctl");
+		free(p);
+		return0;
+	}
+	Established=0;
+	next=(structxinpgen*)p;
+	for(next=(structxinpgen*)((char*)next+next->xig_len);next->xig_len>sizeof(structxinpgen);next=(structxinpgen*)((char*)next+next->xig_len)){
+		tp=(structxtcpcb*)next;
+		if(tp->xt_tp.t_state==TCPS_ESTABLISHED||tp->xt_tp.t_state==TCPS_CLOSE_WAIT)
+			Established++;
+	}
+	free(p);
+#else
	structinpcbcb;
	registerstructinpcb*next;
-#if!(defined(freebsd2)||defined(netbsd2)||defined(openbsd2))
-	registerstructinpcb*prev;
-#endif
	structinpcbinpcb;
	structtcpcbtcpcb;

@@-450,17+481,10@@

	auto_nlist(TCP_SYMBOL,(char*)&cb,sizeof(structinpcb));
	inpcb=cb;
-#if!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))
-	prev=(structinpcb*)auto_nlist_value(TCP_SYMBOL);
-#endif/*!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))*/
	/*
	*	Scanthecontrolblocks
	*/
-#ifdefined(freebsd2)||defined(netbsd1)||defined(openbsd2)
	while((inpcb.INP_NEXT_SYMBOL!=NULL)&&(inpcb.INP_NEXT_SYMBOL!=(structinpcb*)auto_nlist_value(TCP_SYMBOL)))
-#else/*defined(freebsd2)||defined(netbsd1)||defined(openbsd2)*/
-	while(inpcb.INP_NEXT_SYMBOL!=(structinpcb*)auto_nlist_value(TCP_SYMBOL))
-#endif/*defined(freebsd2)||defined(netbsd1)*/
	{
		next=inpcb.INP_NEXT_SYMBOL;

@@-468,16+492,7@@
		snmp_log_perror("TCP_Count_Connections-inpcb");
		break;
		}
-#if!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))
-		if(inpcb.INP_PREV_SYMBOL!=prev){	/*???*/
-			sleep(1);
-			gotoAgain;
-		}
-#endif/*!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))*/
		if(inet_lnaof(inpcb.inp_laddr)==INADDR_ANY){
-#if!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))
-			prev=next;
-#endif/*!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))*/
			continue;
		}
		if(klookup((unsignedlong)inpcb.inp_ppcb,(char*)&tcpcb,sizeof(tcpcb))==0){
@@-488,10+503,8@@
		if((tcpcb.t_state==TCPS_ESTABLISHED)||
		(tcpcb.t_state==TCPS_CLOSE_WAIT))
		Established++;
-#if!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))
-		prev=next;
-#endif/*!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))*/
	}
+#endif
	return(Established);
}
#endif	/*!linux&&!hpux11*/

--=-6mi5uUJulq7+kC/Ng2Cy
Content-Disposition:attachment;filename=patch-5x-tcpTable.c
Content-Type:text/x-c;name=patch-5x-tcpTable.c;charset=ISO-8859-1
Content-Transfer-Encoding:7bit

---agent/mibgroup/mibII/tcpTable.c.orig	FriJul1821:48:412003
+++agent/mibgroup/mibII/tcpTable.c	FriJul1821:52:342003
@@-462,11+462,42@@
TCP_Count_Connections(void)
{
intEstablished;
+#if!(defined(freebsd2)||defined(netbsd2)||defined(openbsd2))
+	intmib[4],len;
+	char*p;
+	structtcpcb*tpcb;
+	structxtcpcb*tp;
+	structxinpgen*next;
+
+	mib[0]=CTL_NET;
+	mib[1]=PF_INET;
+	mib[2]=IPPROTO_TCP;
+	mib[3]=TCPCTL_PCBLIST;
+
+	if(sysctl(mib,4,NULL,&len,NULL,0)!=0){
+		snmp_log_perror("TCP_Count_Connections-sysctl");
+		return0;
+	}
+	if((p=(char*)malloc(len))==NULL){
+		snmp_log_perror("TCP_Count_Connections-malloc");
+		return0;
+	}
+	if(sysctl(mib,4,p,&len,NULL,0)!=0){
+		snmp_log_perror("TCP_Count_Connections-sysctl");
+		free(p);
+		return0;
+	}
+	Established=0;
+	next=(structxinpgen*)p;
+	for(next=(structxinpgen*)((char*)next+next->xig_len);next->xig_len>sizeof(structxinpgen);next=(structxinpgen*)((char*)next+next->xig_len)){
+		tp=(structxtcpcb*)next;
+		if(tp->xt_tp.t_state==TCPS_ESTABLISHED||tp->xt_tp.t_state==TCPS_CLOSE_WAIT)
+			Established++;
+	}
+	free(p);
+#else
structinpcbcb;
registerstructinpcb*next;
-#if!(defined(freebsd2)||defined(netbsd2)||defined(openbsd2))
-registerstructinpcb*prev;
-#endif
structinpcbinpcb;
structtcpcbtcpcb;

@@-477,20+508,14@@

auto_nlist(TCP_SYMBOL,(char*)&cb,sizeof(structinpcb));
inpcb=cb;
-#if!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))
-prev=(structinpcb*)auto_nlist_value(TCP_SYMBOL);
-#endif/*!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))*/
+	
/*
*Scanthecontrolblocks
*/
-#ifdefined(freebsd2)||defined(netbsd1)||defined(openbsd2)
+
while((inpcb.INP_NEXT_SYMBOL!=NULL)
&&(inpcb.INP_NEXT_SYMBOL!=
(structinpcb*)auto_nlist_value(TCP_SYMBOL)))
-#else/*defined(freebsd2)||defined(netbsd1)||defined(openbsd2)*/
-while(inpcb.INP_NEXT_SYMBOL!=
-(structinpcb*)auto_nlist_value(TCP_SYMBOL))
-#endif/*defined(freebsd2)||defined(netbsd1)*/
{
next=inpcb.INP_NEXT_SYMBOL;

@@-499,16+524,8@@
snmp_log_perror("TCP_Count_Connections-inpcb");
break;
}
-#if!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))
-if(inpcb.INP_PREV_SYMBOL!=prev){/*???*/
-sleep(1);
-gotoAgain;
-}
-#endif/*!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))*/
+
if(inet_lnaof(inpcb.inp_laddr)==INADDR_ANY){
-#if!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))
-prev=next;
-#endif/*!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))*/
continue;
}
if(klookup
@@-521,10+538,8@@
if((tcpcb.t_state==TCPS_ESTABLISHED)||
(tcpcb.t_state==TCPS_CLOSE_WAIT))
Established++;
-#if!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))
-prev=next;
-#endif/*!(defined(freebsd2)||defined(netbsd1)||defined(openbsd2))*/
}
+	#endif
return(Established);
}
#endif/*!linux&&!hpux11*/

