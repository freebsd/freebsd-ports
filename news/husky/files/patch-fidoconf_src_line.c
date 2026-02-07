--- fidoconf/src/line.c.orig	2020-01-16 21:50:04 UTC
+++ fidoconf/src/line.c
@@ -3036,7 +3036,7 @@ int parseCarbonDelete(char *token, s_fidoconfig *confi
            break; /* this was the end of a previous set expressions */
        if(cb->move==CC_delete) /* delete */
            break;
-       if(!cb->rule&CC_AND) /* OR */
+       if(!(cb->rule&CC_AND)) /* OR */
            cb->move=CC_delete;
    }
    return 0;
@@ -3086,7 +3086,7 @@ int parseCarbonExtern(char *token, s_fidoconfig *confi
            break; /* this was the end of a previous set expressions */
        if(cb->move==CC_delete) /* delete */
            break;
-       if(!cb->rule&CC_AND){ /* OR */
+       if(!(cb->rule&CC_AND)){ /* OR */
            fc_copyString(token, &(cb->areaName));
            cb->extspawn=1;
            cb->move=CC_copy;
